链接：https://www.nowcoder.com/questionTerminal/00de97733b8e4f97a3fb5c680ee10720?f=discussion&toCommentId=4460137
来源：牛客网

bool cmp(const vector<int> &a, const vector<int> &b){
    if(a[2] < b[2])
        return 1;
    if(a[2] > b[2])
        return 0;
    return a[0] < b[0];
}

class Solution
{
public:
    vector<vector<int> > v;//index char count
    map<char, int> m;
    int index;
    Solution():index(0){

    }
    void HeapAdd(vector<int> tmp){
        v.push_back(tmp);
        int cur = v.size() - 1;
        while(cur > 0){
            int parent = (cur - 1) >> 1;
            if(cmp(v[cur], v[parent])){
                map<char, int>::iterator it1 = m.find(v[cur][1]);
                map<char, int>::iterator it2 = m.find(v[parent][1]);
                swap(it1->second, it2->second);
                swap(v[cur], v[parent]);
                cur = parent;
            }
            else
                return;
        }
    }

    void AdjustHeap(int i){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int tmp;
        bool f = true;
        while(f && left < v.size()){
            f = false;
            if(!cmp(v[i], v[left])){
                tmp = left;
                f = true;
            }
            if(right < v.size() &&
               !cmp(v[left], v[right]) &&
               !cmp(v[i], v[right])){
                tmp = right;
                f = true;
            }
            map<char, int>::iterator it1 = m.find(v[i][1]);
            map<char, int>::iterator it2 = m.find(v[tmp][1]);
            swap(it1->second, it2->second);
            swap(v[i], v[tmp]);
            i = tmp;
            left = 2 * i + 1;
            right = 2 * i + 2;
        }
    }
    //Insert one char from stringstream
    void Insert(char ch)
    {
        map<char, int>::iterator it = m.find(ch);
        if(it == m.end()){
            m[ch] = v.size();
            vector<int> tmp;
            tmp.push_back(index++);
            tmp.push_back(ch);
            tmp.push_back(1);
            HeapAdd(tmp);
        }
        else{
            v[it->second][2]++;
            AdjustHeap(it->second);
        }
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        if(v[0][2] == 1)
            return v[0][1];
        else
            return '#';
    }
};
