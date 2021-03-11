#include <bits/stdc++.h>
using namespace std;

class person_compare{
public:
  bool operator()(pair<string, int> p1,pair<string, int> p2 )
  {
      return p1.second < p2.second;
  }
};
int main() {
    int no_of_transactions, friends;
    cin >> no_of_transactions >> friends;
    string x, y;
    int amount;
    map<string, int> net;
    while(no_of_transactions--)
    {
        cin >> x >> y >> amount;
        if(net.count(x) == 0)
        {
            net[x] = 0;
        }
        if(net.count(y) == 0)
        {
            net[y] = 0;
        }
        net[x] -= amount;
        net[y] += amount;
    }
    // iterate over the persons and add those who have non zero net
    multiset<pair<string, int>, person_compare> m; // as multiset sort on the basis of first element, so we cam either give amount as first element or 
                                //    use our own comparator class;
    for(auto p : net)
    {
        string person = p.first;
         amount = p.second;
         if(net[person] != 0)
         {
             m.insert({person, amount});
         }
    }
    int cnt = 0;
    while(!m.empty())
    {
        auto low = m.begin();
        auto high = prev(m.end());

        int debit = low -> second;
        string debit_person = low -> first;

        int credit = high -> second;
        string credit_person = high -> first;

        m.erase(low);
        m.erase(high);

        int settlement_amount = min(-debit, credit);
        debit += settlement_amount;
        credit -= settlement_amount;

        cout << debit_person << " will pay " << settlement_amount << " to " << credit_person << endl;

        if(debit != 0)
        {
            m.insert({debit_person, debit});
        }
        if(credit != 0)
        {
            m.insert({credit_person, credit});
        }
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
