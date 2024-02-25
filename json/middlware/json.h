/* You may use, distribute and modify this code.
 * Any usage of this code is under the user responsibility only!!! */
 
#ifndef __JSON_H__
#define __JSON_H__

/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
#define JSON_MAX_KEY_SIZE 20
/* ============= function type definitions ============== */
void json_text_add(char* json, char* key, char* val);

void json_text_remove(char* key);

void json_text_update(char* json, char* key, char* val);

void json_text_get(char* json, char* key);

char* json_text_find(char* json, char* key);
/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
#endif // __JSON_H__
