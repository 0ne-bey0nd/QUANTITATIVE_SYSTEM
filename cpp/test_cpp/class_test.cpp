#include "class_test.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
using namespace rapidjson;
int class_test_main(int argc, char* argv[])
{
    const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
    Document d;
    d.Parse(json);

    // 2. ���� DOM �����޸ġ�
    Value& s = d["stars"];
    s.SetInt(s.GetInt() + 1);

    // 3. �� DOM ת����stringify���� JSON��
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);

    // Output {"project":"rapidjson","stars":11}
    std::cout << buffer.GetString() << std::endl;
    return 0;
	std::cout << "this is class test" << std::endl;
	return 0;
}
