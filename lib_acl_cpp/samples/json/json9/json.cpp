#include "stdafx.h"

static void test_type(acl::json& json, const char* name)
{
	const std::vector<acl::json_node*>& nodes1 = json.getElementsByTagName(name);
	if (!nodes1.empty())
	{
		printf("%s: type is %s, value is %s\r\n", name,
			nodes1[0]->get_type(),
			nodes1[0]->get_text() ? nodes1[0]->get_text() : "NULL");
	}
	else
		printf("%s not found\r\n", name);
}

int main()
{
#if 1
	const char* sss =
		"[{\"DataKey1\": \"BindRule\", \"DataValue\": {\"waittime\": \"7\"}, \"null_key\": \"null\"},\r\n"
		"{\"DataKey2\": \"BindRule\", \"DataValue\": {\"waittime\": \"7\"}, \"null_key\": \"null\"},\r\n"
		"{\"member\": [25, 26, 27, 28, 29, true, false]},\r\n"
		"[\"string\", true, false, 100, 200, 300, null, null],\r\n"
		"{\"hello world\": true, \"name\": null, \"age\": 25}]\r\n"
		"{\"hello\" : \"world\"} \r\n";
#else
	const char* sss = "{\"name\": \"100\"}";
#endif

	acl::json json;
	const char* ptr = json.update(sss);

	printf("-------------------------------------------------------\r\n");

	printf("%s\r\n", sss);

	printf("-------------------------------------------------------\r\n");

	printf("json finish: %s, left char: %s\r\n",
		json.finish() ? "yes" : "no", ptr);

	printf(">>>to string: %s\r\n", json.to_string().c_str());

	const char* ss =
		"[{\"DataKey1\": \"BindRule\", \"DataValue\": {\"waittime\": \"7\"}, \"null_key\": \"null\"}, "
		"{\"DataKey2\": \"BindRule\", \"DataValue\": {\"waittime\": \"7\"}, \"null_key\": \"null\"}, "
		"{\"member\": [25, 26, 27, 28, 29, true, false]}, "
		"[\"string\", true, false, 100, 200, 300, null, null], "
		"{\"hello world\": true, \"name\": null, \"age\": 25}]";

	printf("-------------------------------------------------------\r\n");

	if (json.to_string() == ss)
		printf("All OK\r\n\r\n");
	else
	{
		printf("Error\r\n");
		printf("-------------------------------------------------------\r\n");
		printf("%s\r\n", ss);
		printf("-------------------------------------------------------\r\n");
		printf("%s\r\n", json.to_string().c_str());
		printf("\r\n");
		exit (1);
	}
	

	test_type(json, "hello world");
	test_type(json, "name");
	test_type(json, "age");
	test_type(json, "member");
	test_type(json, "DataKey1");
	test_type(json, "DataValue");
	test_type(json, "null_key");
	test_type(json, "string");
	test_type(json, "waittime");

	return 0;
}
