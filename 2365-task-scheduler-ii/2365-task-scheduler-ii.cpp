// tasks.size()>=1 so we can start day from 1
// map<int,int> will store the {tasks[i], day on which this task is done last time}
// if the task[i] is not done before then we can do it on the day mentioned 
// if the task is done before means we need to check on which day it can be done again 
// let say we have task 1 which was already done on day 1 
// then it can be done on day 5 (as per example 1)
// because we have to wait for 3 days (i.e. on day2,day3,day4) 
// 5 can be calculated as m[task[i]]+space+1 
// if currday is less than the required day(m[task[i]]+space+1) (3<5)
// then day will be updated (i.e. wait for 3 days and day will become 5)
// if we have performed the last task (i.e. i==tasks.size()-1) then we will not update the day 

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long day=1;
        map<long long,long long>m;
        for(int i=0;i<tasks.size();i++)
        {
            if(m.find(tasks[i])==m.end())
            {
                m[tasks[i]]=day;
            }
            else 
            {
                if(day<m[tasks[i]]+space+1)
                {
                    day=m[tasks[i]]+space+1;
                    m[tasks[i]]=day;
                }
                else 
                {
                    m[tasks[i]]=day;
                }
            }
            if(i==tasks.size()-1) break;
            day++;
        }
        return day;
    }
};