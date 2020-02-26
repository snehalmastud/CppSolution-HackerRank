
struct Workshops {
    int start_time;
    int duration;
    int end_time; 
};

struct Available_Workshops {
    int n;
    vector <Workshops> w;
};

Available_Workshops *initialize(int *start_time, int *duration, int n) {
    Available_Workshops *paw=new(Available_Workshops);
    Workshops ws;
    
    paw->n=n;
    for (int i=0;i<n;i++) {
        //construct a Workshops
        ws.start_time=start_time[i];
        ws.duration=duration[i];
        ws.end_time=start_time[i]+duration[i];
        paw->w.push_back(ws);   
    }
        
    return paw;    
}

bool compare(Workshops w1, Workshops w2) { 
    return (w1.end_time < w2.end_time); 
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
    // sort workshops by end_time
    sort(ptr->w.begin(),ptr->w.end(),compare); 
    
    // interval scheduling
    int last_processed_time=-1;
    int maxWorkshops=0;
    for (int i=0;i<ptr->n;i++) {
        if (ptr->w[i].start_time >= last_processed_time) {
            last_processed_time=ptr->w[i].end_time;
            maxWorkshops++;
        }
    }

    return maxWorkshops;
}


