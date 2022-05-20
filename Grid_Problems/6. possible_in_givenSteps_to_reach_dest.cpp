// Final Destination
// https://practice.geeksforgeeks.org/problems/final-destination4628/1

bool func(ll a,ll b,ll total){
        if(a==0 && b==0 && total%2==0)   
            return true;
        ll s=abs(a)+abs(b);
	    if(total==s)
	        return true;
	    if(s>total)
	        return false;
	    if(s<total){
	        if((total-s)%2==0)
	            return true;
	        return false;
	    }
}
