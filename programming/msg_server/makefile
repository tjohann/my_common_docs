TARGET := msg_server
OBJS := msg_server.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET) $(OBJS)
	rm -f *~
