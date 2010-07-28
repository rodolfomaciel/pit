#if !defined(__PIT_H__)
#define __PIT_H__

typedef unsigned int  uint;
typedef unsigned long ulong;
typedef unsigned char uchar;

#include <time.h>
#include "object.h"
#include "table.h"

/* Externals. */
extern PTable activities;
extern PTable notes;
extern PTable projects;
extern PTable tasks;
extern PTable users;

#define for_each_activity(ptr) for (ptr = (PActivity)tasks->slots; (ptr - (PActivity)tasks->slots) / sizeof(PActivity) < tasks->number_of_records; ptr++)
#define for_each_note(ptr)     for (ptr = (PNote)tasks->slots;     (ptr - (PNote)tasks->slots)     / sizeof(PNote)     < tasks->number_of_records; ptr++)
#define for_each_project(ptr)  for (ptr = (PProject)tasks->slots;  (ptr - (PProject)tasks->slots)  / sizeof(PProject)  < tasks->number_of_records; ptr++)
#define for_each_task(ptr)     for (ptr = (PTask)tasks->slots;     (ptr - (PTask)tasks->slots)     / sizeof(PTask)     < tasks->number_of_records; ptr++)
#define for_each_user(ptr)     for (ptr = (PUser)users->slots;     (ptr - (PUser)users->slots)     / sizeof(PUser)     < users->number_of_records; ptr++)

/* args.c */
int    pit_arg_is_option(char **arg);
int    pit_arg_option(char **arg);
char  *pit_arg_string(char **arg, char *required);
ulong  pit_arg_number(char **arg, char *required);
time_t pit_arg_time(char **arg, char *required);

/* db.c */
int  pit_init(char *argv[]);
void pit_db_load();
void pit_db_save();
void pit_db_initialize();

/* activity.c project.c task.c user.c */
int   pit_project(char *argv[]);
int   pit_task(char *argv[]);
char *pit_current_user();
PActivity pit_add_activity(ulong id, char *subject, char *message, ulong user_id);

/* util.c */
void die(char *msg, ...);
void perish(char *prefix);
char *mem2str(char *mem, int len);
char *home_dir(char *username, int len);
char *expand_path(char *path, char *expanded);


#endif
