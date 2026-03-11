#include "LinearCharacteristics.h"

using namespace std;

LinearCharacteristics::LinearCharacteristics(float gain, float offset)
{
    m_gain = gain;
    m_offset = offset;
    m_ulim = 999999.0f;  // a large number
    m_llim = -999999.0f; // a large neg. number
}

LinearCharacteristics::LinearCharacteristics(float x1, float x2, float y1, float y2)
{
    m_gain = (y2 - y1) / (x2 - x1);
    m_offset = x1 - y1 / m_gain;
    m_ulim = y2;  // a large number
    m_llim = y1; // a large neg. number
}

LinearCharacteristics::~LinearCharacteristics() {}

float LinearCharacteristics::evaluate(float x)
{
    // calculate result as y(x) = gain * (x - offset)
    float y = m_gain * (x - m_offset);

    if (y < m_llim) {
        return m_llim;
    } else if ( y > m_ulim) {
        return m_ulim;
    }

    return y;
}

void LinearCharacteristics::set_limits(float ll, float ul)
{
    m_llim = ll;
    m_ulim = ul;
}
