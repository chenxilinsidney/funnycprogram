/**
 * @file id_540
 * @brief AOAPC I 540
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-30
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

string line;

// queque team
int queue_team_to_rank[1005];
int queue_rank_to_team[1005];
// queque member
int queue_member[1005][1005];
int queue_member_index[1005];
int queue_member_length[1005];

// team member static
int member_to_team[1000005];

int main()
{
    int num_teams;
    int index_teams = 1;
    while (cin >> num_teams && num_teams != 0) {
        // output
        cout << "Scenario #" << index_teams++ << endl;
        // initialize team member relation
        memset(queue_team_to_rank, 0, sizeof(int) * num_teams);
        memset(queue_rank_to_team, 0, sizeof(int) * num_teams);
        // bitmap for member to get team
        int num_members;
        int name_members;
        for (int i = 0; i < num_teams; i++) {
            cin >> num_members;
            while (num_members--) {
                cin >> name_members;
                member_to_team[name_members] = i;
            }
        }
        cin.get();
        // init for queue
        int queue_team_length = 0;
        int queue_team_first_index = 1;
        int enqueue_value;
        while (getline(cin, line) && line[0] != 'S') {
            if (line[0] == 'E') {
                // get value
                sscanf(line.data() + 7, "%d", &enqueue_value);
                // enqueue
                int judge_team = member_to_team[enqueue_value];
                if (queue_team_to_rank[judge_team] == 0) {
                    // no teammates in the queue
                    // add team to team queue
                    queue_team_to_rank[judge_team] = ++queue_team_length;
                    queue_rank_to_team[queue_team_length] = judge_team;
                    // add member to member queque as first
                    queue_member[judge_team][0] = enqueue_value;
                    queue_member_index[judge_team] = 0;
                    queue_member_length[judge_team] = 1;
                } else {
                    // add member to member queque as last
                    int i = queue_member_index[judge_team];
                    int length = queue_member_length[judge_team];
                    queue_member[judge_team][(i + length) % 1000] =
                        enqueue_value;
                    queue_member_length[judge_team]++;
                }
            } else {
                // dequeue
                // get first rank
                int team = queue_rank_to_team[queue_team_first_index];
                // dequeue
                // team member
                cout << queue_member[team][queue_member_index[team]]
                    << endl;
                queue_member_index[team]++;
                if (queue_member_index[team] == 1000)
                    queue_member_index[team] = 0;
                queue_member_length[team]--;
                // team queue new rank 1 and remove rank
                if (queue_member_length[team] == 0) {
                    queue_team_to_rank[team] = 0;
                    queue_team_length--;
                    queue_team_first_index++;
                    if (queue_team_first_index == 0)
                        queue_team_first_index = 1;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
