CPPFLAGS = -fPIC -std=c++11 -g -O2 -I.
LDFLAGS = -lprotobuf -ljsoncpp -lstdc++

all: libjson2pb.a test_json

clean:
	-rm -f *.o *.a test_json

test_json: test_json.o test.pb.o 
	$(CC) -o $@ $^ -L. -ljson2pb $(LDFLAGS)
test_json.o: test.pb.h

json2pb.o: Bin2Ascii.h

libjson2pb.a: Json2Pb.o
	ar -cr $@ $^

test.pb.h test.pb.cc: test.proto
	protoc --cpp_out=$(shell pwd) test.proto
