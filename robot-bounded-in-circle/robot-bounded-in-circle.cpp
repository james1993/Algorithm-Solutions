class Solution {
public:
    void process(char instruction, vector<int>& position, int& direction)
    {
        switch(instruction)
        {
            case 'G':
                if(direction == 90) position[1]++;
                if(direction == 180) position[0]--;
                if(direction == 270) position[1]--;
                if(direction == 0) position[0]++;
                break;
            case 'L':
                direction = (direction += 90) % 360;
                break;
            case 'R':
                //direction = direction -= 90;
                direction = (direction-= 90) % 360 < 0 ? direction+360 : direction;
                break;
            default:
                break;
        }
    }
    bool isRobotBounded(string instructions) {
        vector<int> position = {0,0};
        int direction = 90; //0 north, 1 east, 2 south, 3 west
        
        for(int i = 0; i < instructions.length(); i++)
        {
            process(instructions[i], position, direction);
        }
        
        return ((position[0] == 0 && position[1] == 0) || (direction != 90));
    }
};