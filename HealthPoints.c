
//
// Created by Shada Sabea on 22/05/2022.
//

#include "HealthPoints.h"

HealthPoints::HealthPoints(const int healthPoints): m_currentHealthPoints(healthPoints), m_maxHealthPoints(healthPoints)
{
    if(healthPoints<=0)
    {
        throw InvalidArgument();
    }
}
HealthPoints HealthPoints::operator+(const int num) const
{
    HealthPoints  healthPoints1=m_currentHealthPoints+num;
    if(healthPoints1.m_currentHealthPoints>m_maxHealthPoints)
    {
        healthPoints1.m_currentHealthPoints=m_maxHealthPoints;
    }
    if (healthPoints1.m_currentHealthPoints<0)
    {
        healthPoints1.m_currentHealthPoints=0;
    }

    return healthPoints1;

}

HealthPoints HealthPoints::operator-(const int num) const
{
HealthPoints  healthPoints1=m_currentHealthPoints-num;
if(healthPoints1.m_currentHealthPoints<0)
{
    healthPoints1.m_currentHealthPoints=0;
}
if(healthPoints1.m_currentHealthPoints>m_maxHealthPoints)
{
    healthPoints1.m_currentHealthPoints=m_maxHealthPoints;
}
return healthPoints1;
}

HealthPoints& HealthPoints::operator+=(const int num)
{
    m_currentHealthPoints+=num;
    return *this;
}

HealthPoints& HealthPoints::operator-=(const int num)
{
    m_currentHealthPoints-=num;
    return *this;
}

 bool operator==(const HealthPoints& healthPoints1, const HealthPoints& healthPoints2)
{
    if(healthPoints1.m_currentHealthPoints==healthPoints2.m_currentHealthPoints)
    {
        return true;
    }
    return false;
}

bool operator<(const HealthPoints& healthPoints1,const HealthPoints& healthPoints2)
{
    if(healthPoints1.m_currentHealthPoints<healthPoints2.m_currentHealthPoints)
    {
        return true;
    }
    return false;
}


 std::ostream& operator<<(std::ostream& os , const HealthPoints& healthPoints)
{
    os<<healthPoints.m_currentHealthPoints<<"("<<healthPoints.m_maxHealthPoints<<")";
     return os;
}

bool operator<=(const HealthPoints& healthPoints1,const HealthPoints& healthPoints2)
{
    if (healthPoints1 == healthPoints2 || healthPoints1 < healthPoints2) {
        return true;
    }
    return false;
}

bool operator!=(const HealthPoints& healthPoints1,const HealthPoints& healthPoints2)
{
    return (!(healthPoints1==healthPoints2));
}

bool operator>=(const HealthPoints& healthPoints1,const HealthPoints& healthPoints2)
{
    if(!(healthPoints1<healthPoints2))
    {
        return true;
    }
    return false;
}

bool operator>(const HealthPoints& healthPoints1,const HealthPoints& healthPoints2)
{
    if(!(healthPoints1<=healthPoints2))
    {
        return true;
    }
    return false;
}


