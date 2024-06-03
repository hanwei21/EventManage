#pragma once

//declare the delegate object,user can't call set&get function!
#define DECLARE_DELEGATE(theDelegate)                                          \
		public:                                                                \
		    theDelegate    GetDelegate(){return m_pDelegate;}                  \
		protected:                                                             \
		    void           SetDelegate(theDelegate pDelegate);                 \
		private:                                                               \
		    theDelegate    m_pDelegate;                                        \
		    int           m_flagDelegate;


//construct delegate
#define INIT_DELEGATE(theDelegateClass)                                        \
	    m_pDelegate = new theDelegateClass();                                  \
	    m_flagDelegate = 0;                                                    \
	    SetDelegate(m_pDelegate);

//deconstruct delegate
#define DELETE_DELEGATE                                                        \
	    if(m_flagDelegate == 0 && m_pDelegate)                                 \
	        delete m_pDelegate;                                                \
	    m_pDelegate = NULL;  


#define BEGIN_SET_DELEGATE(theOwnerClass,theDelegateClass)                     \
	    void theOwnerClass::SetDelegate(theDelegateClass pDelegate)            \
		{ 

#define SET_DELEGATE                                                           \
	    if(m_pDelegate != pDelegate)                                           \
		{                                                                      \
		    if(m_flagDelegate == 0 && m_pDelegate)                             \
		        delete m_pDelegate;                                            \
		                                                                       \
		    m_pDelegate = pDelegate;                                           \
		    m_flagDelegate = 1;                                                \
		}

#define END_SET_DELEGATE                         }



