/**
 * @file id_133.cpp
 * @brief AOAPC I 133
 * @author chenxilinsidney
 * @version 1.0
 * @date 2015-03-28
 */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    // get N, k m
    int N, k, m;
    while (cin >> N >> k >> m && N != 0) {
        cin.get();
        // create circle
        vector<int> circle;
        for (int i = 1; i <= N; i++)
            circle.push_back(i);
        int k_index = k;
        int m_index = N + 1 - m;
        while (k_index < 0) k_index += N;
        while (k_index > N) k_index -= N;
        while (m_index < 0) m_index += N;
        while (m_index > N) m_index -= N;
        if (k_index == 0) k_index = N;
        if (m_index == 0) m_index = N;
        while (circle.size() != 0) {
#ifndef ONLINE_JUDGE
            cout << "next " << k_index << " : " << m_index << endl;
#endif
            int first_remove = circle[k_index - 1];
            int second_remove = circle[m_index - 1];
            if (k_index < m_index) {
                // erase in sequence
                circle.erase(circle.begin() + m_index - 1);
                circle.erase(circle.begin() + k_index - 1);
                // refresh index
                k_index += k - 1;
                m_index -= m + 1;
                // refresh circle size
                N -= 2;
                // output
                cout << setw(3) << first_remove
                    << setw(3) << second_remove;
                if (N == 0) break;
                else cout << ",";
            } else if (k_index > m_index) {
                // erase in sequence
                circle.erase(circle.begin() + k_index - 1);
                circle.erase(circle.begin() + m_index - 1);
                // refresh index
                k_index += k - 2;
                m_index -= m;
                // refresh circle size
                N -= 2;
                // output
                cout << setw(3) << first_remove
                    << setw(3) << second_remove;
                if (N == 0) break;
                else cout << ",";
            } else {
                // erase
                circle.erase(circle.begin() + k_index - 1);
                // refresh index
                k_index += k - 1;
                m_index -= m;
                // refresh circle size
                N--;
                // output
                cout << setw(3) << first_remove;
                if (N == 0) break;
                else cout << ",";
            }
            while (k_index < 0) k_index += N;
            while (k_index > N) k_index -= N;
            while (m_index < 0) m_index += N;
            while (m_index > N) m_index -= N;
            k_index = k_index % N;
            m_index = (m_index + N) % N;
            if (k_index == 0) k_index = N; 
            if (m_index == 0) m_index = N;
#ifndef ONLINE_JUDGE
            cout << "after dec: " << k_index << ","
                << m_index << "," << N << endl;
            for (size_t i = 0; i < circle.size(); i++)
                cout << "remain " << i << ":" << circle[i] << endl;
#endif
        }
        // output result
        cout << endl;
    }
    return 0;
}
