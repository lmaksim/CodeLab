#include "llist\llist_test.h"
#include "json\middlware\json.h"

int main(void)
{
	//llist_main();

	//array_main();
		
    //cli_main();

	char json[] = "student {name:, max} {family: lev}";
	char key[] = "name.max";
	char* rcv = json_string_find(json,key);
	printf("%s", rcv);
}