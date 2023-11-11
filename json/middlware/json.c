/* You may use, distribute and modify this code.
 * Any usage of this code is under the user responsibility only!!! */
 


#include <stddef.h>
#include <stdbool.h>
#include <string.h>

/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */


/* ============= function type definitions ============== */
/* You may use, distribute and modify this code.
 * Any usage of this code is under the user responsibility only!!! */

 /*************************************************/
#include "json.h"
#include <stdio.h>
#include <stdlib.h>

/*************************************************/

/*************************************************/
void json_string_add(char* json, char* key, char* val)
{}

void json_string_remove(char* key)
{}

void json_string_update(char* json, char* key, char* val)
{}

void json_string_get(char* key)
{}

char* json_string_find(char* json, char* key)
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

