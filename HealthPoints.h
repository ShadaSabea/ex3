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


/**
 *
 * @param num the number that will be added to the current health points
 * @return
 */
HealthPoints operator+(const int num) const;
/**
 *
 * @param num the number that will be deducted to the current health points
 * @return
 */
HealthPoints operator-(const int num) const;

HealthPoints& operator+=(const int num);

HealthPoints& operator-=(const int num);

 class InvalidArgument{};


private:
   int m_currentHealthPoints;
   int m_maxHealthPoints;
    friend bool operator==(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);
    friend std::ostream& operator<<(std::ostream&, const HealthPoints&);
    friend bool operator<(const HealthPoints& healthPoints1,const HealthPoints& healthPoints2);
};





bool operator<=(const HealthPoints& healthPoints1,const HealthPoints& healthPoints2) ;

bool operator>=(const HealthPoints& healthPoints1,const HealthPoints& healthPoints2) ;

bool operator>(const HealthPoints& healthPoints1,const HealthPoints& healthPoints2) ;

#endif //EX3_HEALTHPOINTS_H
