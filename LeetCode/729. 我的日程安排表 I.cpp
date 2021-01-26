class MyCalendar {
private:
    int*starts;
    int*ends;
    int n;
public:
    MyCalendar() 
    {
        starts=new int[1000];
        ends=new int[1000];
        n=0;    
    }
    
    bool book(int start, int end) 
    {
            int count=0;
            while(count<n&&(start>=ends[count]||end<=starts[count]))
                count++;
            if(count==n)
            {
                starts[n]=start;
                ends[n]=end;
                n++;
                return 1;
            }
            else
                return 0;
    }
    ~MyCalendar()
    {
        delete starts;
        delete ends;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */