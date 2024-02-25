/* You may use, distribute and modify this code.
 * Any usage of this code is under the user responsibility only!!! */
 

/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */

/* ============= function type definitions ============== */
/* You may use, distribute and modify this code.
 * Any usage of this code is under the user responsibility only!!! */

 /*************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h>
#include "json.h"

/*************************************************/

/*************************************************/
void json_text_update(char* json, char* key, char* val) 
{
	char* f = json_text_find(json, key);
	if (f != NULL)
	{
	}
}

void json_text_add(char* json, char* key, char* val)
{ 	
}

void json_text_remove(char* key)
{}

void json_text_get(char* json, char* key)
{
	char* f = json_text_find(json, key);
	if (f != NULL)
	{
		/* fined next " or [ --> if " ->" if [ -> ]
		example: "secretIdentity": "Dan Jukes"
		         ["Radiation resistance", "Turning tiny", "Radiation blast"] */
	}
}

char* json_text_find(char* json, char* key)
{
	while (true)
	{
		char tkey[JSON_MAX_KEY_SIZE] = { '\0' };
		char* f = strstr(key,".");
		if (f != NULL)
		{
			memcpy(tkey, key, (char)(f-key));
			json = strstr(json, tkey);
			if (json != NULL)
				key = f + 1;
			else
				return NULL;
		}
		else
			return (strstr(json, key));
	}
}

/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */

