#include "Json2Pb.h"
#include "test.pb.h"

#include <stdio.h>

using google::protobuf::Message;

int main()
{
	char buf[8192];
	FILE * fp = fopen("test.json", "r");
	size_t size = fread(buf, 1, 8192, fp);
	fclose(fp);
    
    std::string jsonStr(buf);
	test::ComplexMessage msg;
    if (Json2Pb(msg, jsonStr) < 0 ) {
        std::cout << "ERROR" << std::endl;
    }
	//msg.SetExtension(test::e_bool, false);
	printf("Message: %s\n", msg.DebugString().c_str());
    std::string res;
    Pb2Json(msg, res);
	printf("JSON: %s\n", res.c_str());
}
