/**
 * @file id_10194.c
 * @brief AOAPC I 10194
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-26
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEAM_NAME 35
#define MAX_LINE_WIDTH 105
char line[MAX_LINE_WIDTH];

typedef struct {
    char team_name[MAX_TEAM_NAME];
    int total_points_earned;
    int games_played;
    int wins;
    int ties;
    int losses;
    int goal_difference;
    int goals_scored;
    int goals_against;
} team_struct;

team_struct team[35];

int compare_team_by_name(void const* a, void const* b)
{
    return strcmp(((team_struct*)a)->team_name,
            ((team_struct*)b)->team_name);
}

void string_to_lower(char* str)
{
    while (*str != '\0') {
        *str = tolower(*str);
        str++;
    }
}

int compare_team_by_rank(void const* a, void const* b)
{
    int value = ((team_struct*)a)->total_points_earned -
        ((team_struct*)b)->total_points_earned;
    if (value != 0)
        return value;
    value = ((team_struct*)a)->wins -
        ((team_struct*)b)->wins;
    if (value != 0)
        return value;
    value = ((team_struct*)a)->goal_difference -
        ((team_struct*)b)->goal_difference;
    if (value != 0)
        return value;
    value = ((team_struct*)a)->goals_scored -
        ((team_struct*)b)->goals_scored;
    if (value != 0)
        return value;
    value = ((team_struct*)a)->games_played -
        ((team_struct*)b)->games_played;
    if (value != 0)
        return -1 * value;
    /* case insensive */
    char team_a[MAX_TEAM_NAME];
    memcpy(team_a, ((team_struct*)a)->team_name,
            1 + strlen(((team_struct*)a)->team_name));
    string_to_lower(team_a);
    char team_b[MAX_TEAM_NAME];
    memcpy(team_b, ((team_struct*)b)->team_name,
            1 + strlen(((team_struct*)b)->team_name));
    string_to_lower(team_b);
    return -1 * strcmp(team_a, team_b);
}

int main()
{
    int tournament_count = 0;
    scanf("%d\n", &tournament_count);
    while (tournament_count--) {
        /* get tournament name */
        fgets(line, MAX_LINE_WIDTH, stdin);
        fputs(line, stdout);
        /* get team list */
        int team_numbers, team_index = 0;
        scanf("%d\n", &team_numbers);
        memset(team, 0, sizeof(team[0]) * team_numbers);
        while (team_index < team_numbers) {
            fgets(line, MAX_LINE_WIDTH, stdin);
            int line_length = strlen(line);
            if (line[line_length - 1] == '\n') {
#ifndef ONLINE_JUDGE
                printf("fgets a \\n\n");
#endif
                line[line_length - 1] = '\0';
            }
            memcpy(team[team_index].team_name, line, line_length);
            team_index++;
        }
        /* sort by name */
        qsort(team, team_numbers, sizeof(team[0]), compare_team_by_name);
        /* get games */
        int games_numbers, games_index = 0;
        scanf("%d\n", &games_numbers);
        while (games_index < games_numbers) {
            /* get games information */
            fgets(line, MAX_LINE_WIDTH, stdin);
            char team_a[MAX_TEAM_NAME];
            char team_b[MAX_TEAM_NAME];
            int team_a_goals = 0;
            int team_b_goals = 0;
            sscanf(line, "%[^#]#%d@%d#%[^\n]", team_a, &team_a_goals,
                    &team_b_goals, team_b);
#ifndef ONLINE_JUDGE
            printf("game:%s\n", line);
            printf("%s, %d, %d, %s\n", team_a, team_a_goals,
                    team_b_goals, team_b);
#endif
            /* record information to team */
            team_struct* team_a_ptr = bsearch(team_a,
                    team, team_numbers, sizeof(team[0]), compare_team_by_name);
            team_struct* team_b_ptr = bsearch(team_b,
                    team, team_numbers, sizeof(team[0]), compare_team_by_name);
#ifndef ONLINE_JUDGE
            printf("search:%s\n", (*team_a_ptr).team_name);
            printf("search:%s\n", (*team_b_ptr).team_name);
#endif
            (*team_a_ptr).goals_scored += team_a_goals;
            (*team_a_ptr).goals_against += team_b_goals;
            (*team_a_ptr).goal_difference += team_a_goals -team_b_goals;
            (*team_a_ptr).games_played++;
            (*team_b_ptr).goals_scored += team_b_goals;
            (*team_b_ptr).goals_against += team_a_goals;
            (*team_b_ptr).goal_difference += team_b_goals -team_a_goals;
            (*team_b_ptr).games_played++;
            if (team_a_goals > team_b_goals) {
                (*team_a_ptr).total_points_earned += 3;
                (*team_a_ptr).wins++;
                (*team_b_ptr).losses++;
            } else if (team_a_goals < team_b_goals) {
                (*team_b_ptr).total_points_earned += 3;
                (*team_b_ptr).wins++;
                (*team_a_ptr).losses++;
            } else {
                (*team_a_ptr).total_points_earned += 1;
                (*team_b_ptr).total_points_earned += 1;
                (*team_a_ptr).ties++;
                (*team_b_ptr).ties++;
            }
            games_index++;
        }
        /* get team rank */
        qsort(team, team_numbers, sizeof(team[0]), compare_team_by_rank);
        /* display total information */
        team_index = team_numbers;
        int team_rank = 1;
        while (team_index--) {
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
                    team_rank++,
                    team[team_index].team_name,
                    team[team_index].total_points_earned,
                    team[team_index].games_played,
                    team[team_index].wins,
                    team[team_index].ties,
                    team[team_index].losses,
                    team[team_index].goal_difference,
                    team[team_index].goals_scored,
                    team[team_index].goals_against);
        }
        if (tournament_count)
            printf("\n");
    }
    return 0;
}
