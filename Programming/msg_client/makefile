TARGET := msg_client
OBJS := msg_client.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET) $(OBJS)
	rm -f *~
