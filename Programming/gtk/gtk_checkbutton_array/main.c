#include <gtk/gtk.h>

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct {
	char hostname[HOST_NAME_MAX + 1];
	char ip_addr[HOST_NAME_MAX];  // TODO: as string?
	int sfd;
} baalue_node_t;

typedef struct {
	baalue_node_t *array_of_nodes;
	unsigned short num_nodes; /* should be large enough */
} baalue_nodes_t;

baalue_nodes_t *
get_active_baalue_nodes()
{
	baalue_node_t *array_of_nodes = NULL;
	baalue_nodes_t *baalue_nodes = NULL;

	int n = -1;
	int num_nodes_max = 4;  /* range_max - range_min */
	int count_nodes = 0;
	do {
		array_of_nodes = realloc(array_of_nodes, (count_nodes + 1) * sizeof(baalue_node_t));
		if (array_of_nodes == NULL)
			goto error;
		memset(&array_of_nodes[count_nodes],0 , sizeof(baalue_node_t));

		n = snprintf(array_of_nodes[count_nodes].hostname, HOST_NAME_MAX + 1,
			     "hostname.%d", count_nodes);
		if (n == -1)
			goto error;

		count_nodes++;
	} while (count_nodes < num_nodes_max);

	baalue_nodes = malloc(sizeof(baalue_nodes_t));
	baalue_nodes->array_of_nodes = array_of_nodes;
	baalue_nodes->num_nodes = count_nodes;

	return baalue_nodes;
error:
	printf("something went wrong\n");

	if (array_of_nodes != NULL)
		free(array_of_nodes);

	return NULL;
}

void
free_baalue_nodes_instance(baalue_nodes_t *baalue_nodes)
{
	if (baalue_nodes != NULL) {
		if (baalue_nodes->array_of_nodes !=NULL)
			free(baalue_nodes->array_of_nodes);
		else
			printf("baalue_nodes->array_of_nodes == NULL -> nothing to free\n");
	} else {
		printf("baalue_nodes == NULL -> nothing the free\n");
	}
}

int
print_baalue_nodes_instance(baalue_nodes_t *baalue_nodes)
{
	if (baalue_nodes == NULL) {
		printf("baalue_nodes == NULL -> nothing to print\n");
		return -1;
	}

	int i = 0;
	for(i = 0; i < baalue_nodes->num_nodes; i++)
		printf("array_of_nodes[%d].hostname: %s\n", i, baalue_nodes->array_of_nodes[i].hostname);

	return 0;
}

void toggle_title(GtkWidget *widget, gpointer data)
{
	baalue_node_t *i = data;

	printf("data: %s \n", i->hostname);
}

int main(int argc, char** argv) {

	GtkWidget *window;
	GtkWidget *vbox;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_container_set_border_width(GTK_CONTAINER(window), 15);
	gtk_window_set_default_size(GTK_WINDOW(window), 230, 150);
	gtk_window_set_title(GTK_WINDOW(window), "GtkCheckButton");

	vbox = gtk_vbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(window), vbox);


        /*
	 * --- get nodes ----
	 */

	/* broadcast to get active nodes */
	baalue_nodes_t *baalue_nodes = get_active_baalue_nodes(); // TODO: search range
	if (baalue_nodes == NULL) {
		printf("baalue_nodes == NULL\n");
		exit(EXIT_FAILURE);
	}

	/*
	 * to free all:
	   free_baalue_nodes_instance(baalue_nodes);
	*/

	/*
	 * to print content:
	 */
	int ret = print_baalue_nodes_instance(baalue_nodes);
	if (ret == -1)
		printf("could not print baalue_nodes content\n");


	/*
	 * create array of check_buttons
	 */
	GtkWidget *array_of_cb[baalue_nodes->num_nodes];

	// ---- start check buttons ----
	int i = 0;
	for (i = 0; i < baalue_nodes->num_nodes; i++) {

		printf("value of i: %d\n", i);
		array_of_cb[i] = gtk_check_button_new_with_label("Show title");
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(array_of_cb[i]), FALSE);

		GTK_WIDGET_UNSET_FLAGS(array_of_cb[i], GTK_CAN_FOCUS);
		gtk_container_add(GTK_CONTAINER(vbox), array_of_cb[i]);

		g_signal_connect(array_of_cb[i], "clicked",
				 G_CALLBACK(toggle_title), (gpointer) &baalue_nodes->array_of_nodes[i]);
	}

	g_signal_connect(window, "destroy",
			 G_CALLBACK(gtk_main_quit), NULL);

	gtk_widget_show_all(window);

	gtk_main();

	return 0;
}
