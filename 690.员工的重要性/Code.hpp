/*
Employee info
class Employee {
public:
    // It's the unique ID of each node.
    //     // unique id of this employee
    //         int id;
    //             // the importance value of this employee
    //                 int importance;
    //                     // the id of direct subordinates
    //                         vector<int> subordinates;
    //                         
};
*/
class Solution {
public:
    int dfs(int id, unordered_map<int, Employee*>& info)
    {
        int ret = info[id]->importance;

        for (int subid : info[id]->subordinates)
        {
            ret += dfs(subid, info);

        }

        return ret;

    }

    int getImportance(vector<Employee*> employees, int id) {
        if (employees.empty())
        {
            return 0;

        }

        unordered_map<int, Employee*> info;
        for (auto e : employees)
        {
            info[e->id] = e;

        }

        return dfs(id, info);

    }

};



// bfs
/*
   Employee info
   class Employee {
   public:
// It's the unique ID of each node.
// unique id of this employee
int id;
// the importance value of this employee
int importance;
// the id of direct subordinates
vector<int> subordinates;

};
*/
class Solution {
public:

    int getImportance(vector<Employee*> employees, int id) {
        // 存储 id 
        queue<int> q;
        int ans = 0;

        std::unordered_map<int, Employee*> info;
        for (auto e : employees)
        {
            info[e->id] = e;
        }

        q.push(id);
        while (!q.empty())
        {
            int tmp = q.front();
            q.pop();

            ans += info[tmp]->importance;

            for (auto e : info[tmp]->subordinates)
            {
                q.push(e);
            }
        }

        return ans;
    }


};
}
}
}
}
}
