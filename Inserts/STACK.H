// CStack class

class CStack
{
public:
   // Construction
	CStack(int Size = 2000);   // standard constructor
   virtual ~CStack();
   int      PeekTop(char *Data, int NumBytes);
   int      IsEmpty();
   int      CurrentSize();
   int      MaxSize();
   int      Push(const char *Data, int NumBytes);
   int      Pop(char *Data, int NumBytes);

protected:
   int      m_size;
   int      m_pointer;
   char    *m_data;
};