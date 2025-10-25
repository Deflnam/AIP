#include <iostream>
#include <climits>

bool isPyth(unsigned a, unsigned b, unsigned c);
bool checkOverflow(unsigned a, unsigned b, unsigned c);



int main()
{
    using u_t = unsigned;
    u_t a=0,b=0,c=0;
    size_t count = 0;
    std::cin>>c>>b;
    

    while(std::cin>>a)
    {
        if (checkOverflow(a, b, c))
        {
            std::cerr << "Error\n";
            return 2;
        }

        count += isPyth(a,b,c)? 1:0;
        c=b;
        b=a;
    }


    if(std::cin.eof())
    {
        std::cout << count;
        std::cout<<'\n';

    }

    else if (std::cin.fail())
    {
        std::cerr<< "Error\n";
        return 1;

    }


}

bool isPyth(unsigned a, unsigned b, unsigned c )
{    
    bool p = a*a == (b*b + c*c);
    p = p || (b*b == (a*a + c*c));
    p = p || (c*c == (a*a + b*b));
    return p;
}

bool checkOverflow(unsigned a, unsigned b, unsigned c)
{
   
    if (a > 1 && a > (std::numeric_limits<unsigned>::max() / a)) return true;
    if (b > 1 && b > (std::numeric_limits<unsigned>::max() / b)) return true;
    if (c > 1 && c > (std::numeric_limits<unsigned>::max() / c)) return true;
    
    unsigned a2 = a * a;
    unsigned b2 = b * b;
    unsigned c2 = c * c;
    
    
    if (b2 > std::numeric_limits<unsigned>::max() - c2) return true;
    unsigned ab_sum = a2 + b2;
    if (ab_sum < a2 || ab_sum < b2) return true; 
    if (ab_sum > std::numeric_limits<unsigned>::max() - c2) return true;
    
    return false;
}