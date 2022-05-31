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
HealthPoints(int m_currentHealthPoints=100);


/**
 * copy constructor
 * @param healthPoints
 */
HealthPoints(const HealthPoints& healthPoints)=default;

/**
 * destructor
 */
~HealthPoints()=default;
/**
 * operator = between 2 objects
 * @param healthPoints
 * @return object after being updated
 */
HealthPoints& operator=(const HealthPoints& healthPoints)=default;
/**
 * operator = between object and int
 * @param healthPoints
 * @return  object after being updated
 */
HealthPoints& operator=(int healthPoints);
/**
 * operator +=
 * @param healthPoints
 * @return  adding the received  health points to my health points
 */

HealthPoints& operator+=(const int increase);

/**
 * operator -=
 * @param healthPoints
 * @return removing health points the same as being accepted
 */
HealthPoints& operator-=(const int decrease);


 class InvalidArgument{};


private:
   int m_currentHealthPoints;
   int m_maxHealthPoints;
   /**
    *operator ==
    * @param healthPoints1
    * @param healthPoints2
    * @return true if the two objects are the same
    */
    friend bool operator==(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2);
    /**
     *
     * @return printing data
     */
    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& healthPoints);
    /**
     * comparison between two objects
     * @param healthPoints1
     * @param healthPoints2
     * @return true if the objects are te same
     */
    friend bool operator<(const HealthPoints& healthPoints1,const HealthPoints& healthPoints2);
};




/**
 * removing health points object from another
 * @param healthPoints1
 * @param num
 * @return object after being changed
 */
HealthPoints operator-(const HealthPoints& healthPoints1,const int num);

HealthPoints operator-(const int num,const HealthPoints& healthPoints1);

/**
 *
 * @param num
 * @param healthPoints2
 * @return sum of the 2 health points
 */
HealthPoints operator+(const int num,const HealthPoints& healthPoints2);//000000000
/**
 *
 * @param healthPoints2
 * @param num
 * @return sum of the 2 health points
 */
HealthPoints operator+(const HealthPoints& healthPoints2,const int num);//000000000

/**
 * comparison between 2 objects
 * @param healthPoints1
 * @param healthPoints2
 * @return true if the first object <= second object else false
 */
bool operator<=(const HealthPoints& healthPoints1,const HealthPoints& healthPoints2) ;
/**
 * comparison between 2 objects
 * @param healthPoints1
 * @param healthPoints2
 * @return true if the first object >= second object
 */
bool operator>=(const HealthPoints& healthPoints1,const HealthPoints& healthPoints2) ;
/**
 * comparison between 2 objects
 * @param healthPoints1
 * @param healthPoints2
 * @return true if the first object > second object
 */
bool operator>(const HealthPoints& healthPoints1,const HealthPoints& healthPoints2);

bool operator!=(const HealthPoints& healthPoints1,const HealthPoints& healthPoints2);

#endif //EX3_HEALTHPOINTS_H
