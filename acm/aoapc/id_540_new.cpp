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
#include <queue>

using namespace std;

string line;

// queque team exit flag
bool flag_team_in_queue[1005];
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
        memset(flag_team_in_queue, 0, sizeof(int) * num_teams);
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
        queue<int> queue_member[num_teams];
        queue<int> queue_team;
        int enqueue_value;
        while (getline(cin, line) && line[0] != 'S') {
            if (line[0] == 'E') {
                // get value
                sscanf(line.data() + 7, "%d", &enqueue_value);
                // enqueue
                int judge_team = member_to_team[enqueue_value];
                // add member to member queque
                queue_member[judge_team].push(enqueue_value);
                // no teammates in the queue
                if (flag_team_in_queue[judge_team] == 0) {
                    // add team to team queue and set exist flag
                    flag_team_in_queue[judge_team] = 1;
                    queue_team.push(judge_team);
                }
            } else {
                // dequeue
                // get first rank
                int judge_team = queue_team.front();
                // judge_team member
                cout << queue_member[judge_team].front() << endl;
                queue_member[judge_team].pop();
                // last member
                if (queue_member[judge_team].empty()) {
                    // remove team from team queue and unset exist flag
                    flag_team_in_queue[judge_team] = 0;
                    queue_team.pop();
                }
            }
        }
        cout << endl;
    }
    return 0;
}
