#include <bits/stdc++.h>
using namespace std;

class Cashier {
private:
    int cdiscount, cn;
    unordered_map<int, int> hashmap;
    int ccount;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices){
        cn = n;
        ccount = 0;
        cdiscount = discount;
        for (int i = 0; i < products.size(); ++i){
            hashmap[products[i]] = prices[i];
        }
    }

    double getBill(vector<int> product, vector<int> amount) {
        ++ccount;
        double res = 0;
        for (int i = 0; i < product.size(); ++i){
            int price = hashmap[product[i]];
            res += price * amount[i];
        }
        if (ccount == cn) {
            res = res - res * cdiscount / 100;
            ccount = 0;
        }
        return res;
    }
};

int main() {
    vector<int> products{1,2,3,4,5,6,7};
    vector<int> prices{100,200,300,400,300,200,100};
    Cashier cashier = Cashier(3, 50, products, prices);
    cout << cashier.getBill({1,2},{1,2}) << endl;
    cout << cashier.getBill({3,7},{10,10}) << endl;
    cout << cashier.getBill({1,2,3,4,5,6,7},{1,1,1,1,1,1,1}) << endl;
    cout << cashier.getBill({4},{10}) << endl;
    cout << cashier.getBill({7,3},{10,10}) << endl;
    cout << cashier.getBill({7,5,3,1,6,4,2},{10,10,10,9,9,9,7}) << endl;
    return 0;
}
