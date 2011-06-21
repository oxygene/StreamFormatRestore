#ifndef STREAMFORMATRESTORE_H_INCLUDED
#define STREAMFORMATRESTORE_H_INCLUDED

class CStreamFormatRestore
{
public:
    CStreamFormatRestore(std::ostream& f_stream)
        : m_stream(f_stream)
    {
        // save format state
        m_fmtFlags = m_stream.flags();
        m_precision = m_stream.precision();
        m_fill = m_stream.fill();
    }

    ~CStreamFormatRestore()
    {
        // restore format state
        m_stream.flags(m_fmtFlags);
        m_stream.precision(m_precision);
        m_stream.fill(m_fill);
    }

private:
    std::ostream& m_stream;

    std::ios_base::fmtflags m_fmtFlags;
    std::streamsize m_precision;
    char m_fill;
};

#endif // STREAMFORMATRESTORE_H_INCLUDED
