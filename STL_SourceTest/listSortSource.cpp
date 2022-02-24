#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <list>
using namespace std;
//list 不能使用sort函数，因为list的迭代器是bidirectional_iterator, 而sort
//sort函数要求random_access_iterator

void sort()
{
    list<int> Nums = { 5,8,2,4,9,0 };
    // list<int> Mun2 = { 1,3,6 };
    // list<int> DDD = { 0,2,4,5,8,9 };
    // Mun2.merge(DDD);
    list<int> carry; //中转站
    list<int> counter[64];  //用来保存一系列的合并后的有序链表，每一层保存的最大结点数目1,2,4,...
    int fill = 0;   //记录了counter数组现在最多使用了几层
    while (!Nums.empty())
    {
        carry.splice(carry.begin(), Nums, Nums.begin());  //每次取出一个元素
        int i = 0;
        while (i < fill && !counter[i].empty())
        {
            counter[i].merge(carry);  //将carry中的元素合并到counter[i]中
            carry.swap(counter[i++]);  //交换之后counter[i-1]为空
        }
        carry.swap(counter[i]);
        if (i == fill) ++fill;
    }
    int a = 0;
    for (int i = 1; i < fill; ++i)
    {
        counter[i].merge(counter[i - 1]);   //将所有保存在counter中的有序链表合并到一起
    }
    Nums.swap(counter[fill - 1]);   //将在counter[fill-1]排序好的链表交换给this链表。
}

int main() {

    int b = 0;
    sort();

    return 0;
}