class Robot {
public:
    int dx, dy;
    int x , y;
    int mx,my;
    int perimeter;
    Robot(int width, int height) {
        dx = 1;
        dy = 0;
        x = 0 , y =0;
        mx = width;
        my = height;
        perimeter = 2*(mx+my-2);
    }
    
    void step(int num) {
        num = num%perimeter;
        if(num==0) num = perimeter;
        while(num--){
            int nx = x + dx;
            int ny = y + dy;
            if(nx<mx && nx>=0 && ny<my && ny>=0){
                x = nx;
                y = ny;
            }
            else{
                int temp = dx;
                dx = -dy;
                dy = temp;
                x = x + dx;
                y = y + dy;
            }
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        if(dx==1 && dy==0){
            return "East";
        }
        else if(dx==0 && dy==1){
            return "North";
        }
        else if(dx==-1 && dy==0){
            return "West";
        }
        return "South"; 
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */