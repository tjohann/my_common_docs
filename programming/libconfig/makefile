TARGET := config_example
OBJS := config_example.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) `pkg-config --cflags --libs libconfig` $^ -o $@

clean:
	rm -f $(TARGET) $(OBJS)
	rm -f *~

run:
	./config_example
