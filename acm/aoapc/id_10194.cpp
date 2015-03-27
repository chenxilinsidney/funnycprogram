/**
 * @file id_10194.cpp
 * @brief AOAPC I 10194
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-26
 */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

#define MAX_TEAM_NAME 35

typedef struct {
    string team_name;
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

bool compare_team_by_rank(const team_struct& a, const team_struct& b)
{
    int value = a.total_points_earned - b.total_points_earned;
    if (value != 0)
        return value > 0;
    value = a.wins - b.wins;
    if (value != 0)
        return value > 0;
    value = a.goal_difference - b.goal_difference;
    if (value != 0)
        return value > 0;
    value = a.goals_scored - b.goals_scored;
    if (value != 0)
        return value > 0;
    value = a.games_played - b.games_played;
    if (value != 0)
        return value < 0;
    // case insensive
    string team_a = a.team_name;
    for (string::iterator it = team_a.begin(); it != team_a.end(); it++)
        *it = tolower(*it);
    string team_b = b.team_name;
    for (string::iterator it = team_b.begin(); it != team_b.end(); it++)
        *it = tolower(*it);
    return -1 * team_a.compare(team_b);
}

int main()
{
    int tournament_count;
    cin >> tournament_count;
    // remove '\n'
    cin.get();
    while (tournament_count--) {
        // get tournament name
        string tournament;
        getline(cin, tournament);
        cout << tournament << endl;
        // get team list
        int team_numbers;
        cin >> team_numbers;
        cin.get();
        map<string, int> team_map;
        team_map.clear();
        for (int team_index = 0; team_index < team_numbers; team_index++) {
            getline(cin, team[team_index].team_name);
            team[team_index].total_points_earned = 0;
            team[team_index].games_played = 0;
            team[team_index].wins = 0;
            team[team_index].ties = 0;
            team[team_index].losses = 0;
            team[team_index].goals_scored = 0;
            team[team_index].goal_difference = 0;
            team[team_index].goals_against = 0;
            team_map.insert(pair<string, int>(
                        team[team_index].team_name,
                        team_index));
        }
        // get games
        int games_numbers;
        cin >> games_numbers;
        cin.get();
        while (games_numbers--) {
            string line;
            getline(cin, line);
            int postion_1 = line.find('#');
            int postion_2 = line.find('@');
            int postion_3 = line.rfind('#');
            string team_a = line.substr(0, postion_1);
            string team_b = line.substr(postion_3 + 1);
            int team_a_goals = atoi((line.substr(postion_1 + 1,
                        postion_2 - postion_1 - 1)).data());
            int team_b_goals = atoi((line.substr(postion_2 + 1,
                        postion_3 - postion_2 - 1)).data());
            // record information to team
            team_struct* team_a_ptr = &team[team_map[team_a]];
            team_struct* team_b_ptr = &team[team_map[team_b]];
            team_a_ptr->goals_scored += team_a_goals;
            team_a_ptr->goals_against += team_b_goals;
            team_a_ptr->goal_difference += team_a_goals -team_b_goals;
            team_a_ptr->games_played++;
            team_b_ptr->goals_scored += team_b_goals;
            team_b_ptr->goals_against += team_a_goals;
            team_b_ptr->goal_difference += team_b_goals -team_a_goals;
            team_b_ptr->games_played++;
            if (team_a_goals > team_b_goals) {
                team_a_ptr->total_points_earned += 3;
                team_a_ptr->wins++;
                team_b_ptr->losses++;
            } else if (team_a_goals < team_b_goals) {
                team_b_ptr->total_points_earned += 3;
                team_b_ptr->wins++;
                team_a_ptr->losses++;
            } else {
                team_a_ptr->total_points_earned += 1;
                team_b_ptr->total_points_earned += 1;
                team_a_ptr->ties++;
                team_b_ptr->ties++;
            }
        }
        // get team rank
        sort(team, team + team_numbers, compare_team_by_rank);
        /* display total information */
        for (int team_index = 0; 
                team_index < team_numbers; team_index++) {
            cout << team_index + 1 << ") "
                << team[team_index].team_name << " "
                << team[team_index].total_points_earned << "p, "
                << team[team_index].games_played << "g ("
                << team[team_index].wins << "-"
                << team[team_index].ties << "-"
                << team[team_index].losses << "), "
                << team[team_index].goal_difference << "gd ("
                << team[team_index].goals_scored << "-"
                << team[team_index].goals_against << ")" << endl;
        }
        if (tournament_count)
            cout << endl;
    }
    return 0;
}
