//
// Created by Shada Sabea on 22/05/2022.
//

#include "HealthPoints.h"

HealthPoints& HealthPoints::operator=(const int healthPoints){
    if(healthPoints<=0)
    {
        throw InvalidArgument();
    }
    m_currentHealthPoints=healthPoints;
    m_maxHealthPoints=healthPoints;
    return *this;
}

HealthPoints::HealthPoints(const int healthPoints): m_currentHealthPoints(healthPoints), m_maxHealthPoints(healthPoints)
{
    if(healthPoints<=0)
    {

         throw InvalidArgument();
    }
}



HealthPoints operator+(const int num,const HealthPoints& healthPoints1)
{
    HealthPoints result=healthPoints1;
    result+= num ;
    return result;

}

HealthPoints operator+(const HealthPoints& healthPoints1,const int num)
{
    HealthPoints result=healthPoints1;
    result+= num;
    return result;
}

HealthPoints operator-(const HealthPoints& healthPoints1,const int num)
{
    HealthPoints result=healthPoints1;
    result-= num;
    return result;
}


HealthPoints& HealthPoints::operator+=(const HealthPoints& healthPoints)
{
    m_currentHealthPoints+=healthPoints.m_currentHealthPoints;

    if(m_currentHealthPoints>m_maxHealthPoints)
    {
        m_currentHealthPoints=m_maxHealthPoints;
    }
    if(m_currentHealthPoints<0)
    {
        m_currentHealthPoints=0;
    }
    return *this;
}

HealthPoints& HealthPoints::operator-=(const HealthPoints& healthPoints)
{
    m_currentHealthPoints-=healthPoints.m_currentHealthPoints;
    if(m_currentHealthPoints>m_maxHealthPoints)
    {
        m_currentHealthPoints=m_maxHealthPoints;
    }
    if(m_currentHealthPoints<0)
    {
        m_currentHealthPoints=0;
    }
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

