//
// Created by Shada Sabea on 22/05/2022.
//

#ifndef EX3_HEALTHPOINTS_H
#define EX3_HEALTHPOINTS_H
#include <ostream>



class HealthPoints{
public:
    /**
     * constructor
     * @param healthPoints the number of health points
     */
HealthPoints(const int m_currentHealthPoints=100);

HealthPoints(const HealthPoints& healthPoints)=default;

~HealthPoints()=default;

HealthPoints& operator=(const HealthPoints& healthPoints)=default;

HealthPoints& operator=(const int healthPoints);


HealthPoints& operator+=(const HealthPoints& healthPoints);

HealthPoints& operator-=(const HealthPoints& healthPoints);

    /**
 *
 * @param num the number that will be deducted to the current health points
 * @return
 */



 class InvalidArgument{};


private:
   int m_currentHealthPoints;
   int m_maxHealthPoints;
    friend bool operator==(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);
    friend std::ostream& operator<<(std::ostream&, const HealthPoints&);
    friend bool operator<(const HealthPoints& healthPoints1,const HealthPoints& healthPoints2);
};





HealthPoints operator-(const HealthPoints& healthPoints1,const int num);


HealthPoints operator+(const int num,const HealthPoints& healthPoints2);//000000000
HealthPoints operator+(const HealthPoints& healthPoints2,const int num);//000000000


bool operator<=(const HealthPoints& healthPoints1,const HealthPoints& healthPoints2) ;

bool operator>=(const HealthPoints& healthPoints1,const HealthPoints& healthPoints2) ;

bool operator>(const HealthPoints& healthPoints1,const HealthPoints& healthPoints2) ;

#endif //EX3_HEALTHPOINTS_H
