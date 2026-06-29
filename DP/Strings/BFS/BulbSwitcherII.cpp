class Solution {
public:
    int flipLights(int n, int m) {
        if(m == 0)
        {
            return 1;
        }else{
            switch(n)
            {
                case 1: return 2;break;
                case 2: return (m == 1) ? 3 : 4;break;
                default:
                switch(m)
                {
                    case 1: return 4;break;
                    case 2: return 7;break;
                    default: return 8;break;
                }
                break;
            }
        }
    }
};