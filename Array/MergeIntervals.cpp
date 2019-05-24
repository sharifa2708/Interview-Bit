class Solution{
public:
	bool doesIntersect(Interval a, Interval b){
		if(min(a.end, b.end)<max(a.start, b.start))return false;
		return true;
	}

	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval){
		int sz= intervals.size();
		vector<Interval> result;

		//if size=0
		if(sz==0){
			result.push_back(newInterval);
			return result;
		}
		//newInterval at strat or end without overlap
		if(newInterval.end < intervals[0].start || newInterval.start > intervals[sz-1].end){
			if(newInterval.end<intervals[0].start){
				result.push_back(newInterval);
			}
			for(int i=0; i<sz; i++){
				result.push_back(intervals[i]);
			}
			if(newInterval.start > intervals[sz-1].end){
				result.push_back(newInterval);
			}
			return result;
		}
		for(int i=0; i<sz-1; i++){
			bool doesIntersect(intervals[i], newInterval);
			if(!intersect){
				result.push_back(intervals[i]);

				if(i<sz-1 && newInterval.start > intervals[i].start && newInterval.end < intervals[i+1]){
					result.push_back(newInterval);
				}continue;
			}
			//intersect
			int st=i;
			while(i<sz && intersect){
				i++;
				if(i==sz) intersect=false;
				else{
					intersect = doesIntersect(intervals[i], newInterval);
				}
			}
			i--;

			Interval toInsert(min(newInterval.start, intervals[st].start), max(newInterval.end, intervals[i].end));
			result.push_back(toInsert);
		}
		return result;

	}
};