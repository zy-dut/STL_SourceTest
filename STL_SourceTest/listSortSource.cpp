#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <list>
using namespace std;
//list ����ʹ��sort��������Ϊlist�ĵ�������bidirectional_iterator, ��sort
//sort����Ҫ��random_access_iterator

void sort()
{
    list<int> Nums = { 5,8,2,4,9,0 };
    // list<int> Mun2 = { 1,3,6 };
    // list<int> DDD = { 0,2,4,5,8,9 };
    // Mun2.merge(DDD);
    list<int> carry; //��תվ
    list<int> counter[64];  //��������һϵ�еĺϲ������������ÿһ�㱣����������Ŀ1,2,4,...
    int fill = 0;   //��¼��counter�����������ʹ���˼���
    while (!Nums.empty())
    {
        carry.splice(carry.begin(), Nums, Nums.begin());  //ÿ��ȡ��һ��Ԫ��
        int i = 0;
        while (i < fill && !counter[i].empty())
        {
            counter[i].merge(carry);  //��carry�е�Ԫ�غϲ���counter[i]��
            carry.swap(counter[i++]);  //����֮��counter[i-1]Ϊ��
        }
        carry.swap(counter[i]);
        if (i == fill) ++fill;
    }
    int a = 0;
    for (int i = 1; i < fill; ++i)
    {
        counter[i].merge(counter[i - 1]);   //�����б�����counter�е���������ϲ���һ��
    }
    Nums.swap(counter[fill - 1]);   //����counter[fill-1]����õ���������this����
}

int main() {

    int b = 0;
    sort();

    return 0;
}