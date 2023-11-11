/* You may use, distribute and modify this code.
 * Any usage of this code is under the user responsibility only!!! */
 
#ifndef __JSON_H__
#define __JSON_H__

#include <stddef.h>
#include <stdbool.h>

/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
#define JSON_MAX_KEY_SIZE 20
/* ============= function type definitions ============== */
void json_string_add(char* json, char* key, char* val);

void json_string_remove(char* key);

void json_string_update(char* json, char* key, char* val);

void json_string_get(char* key);

char* json_string_find(char* json, char* key);
/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
#endif // __JSON_H__
