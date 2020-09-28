#pragma once

namespace Matheus
{
	template <class TL> class List
	{
	private:
		
		template <class TE> class Element
		{
		private:
			Element<TE>* pNext;
			TE data;

		public:
			Element() { pNext = nullptr; }
			~Element() { }
			Element<TE>* getNext() { return pNext; }
			TE getData() { return data; }
			void setNext(Element<TE>* pNext) { this->pNext = pNext; }
			void setData(TE data) { this->data = data; }
		};

		Element<TL>* pFirst;
		Element<TL>* PLast;
		int size;
	
	public:
		List();
		~List();
		void push(TL pData);
		TL pop(TL pData);
		void remove(TL PData);
		int getSize() { return size; }
		TL getElement(int i);
	};
	
	template<class TL>
	inline List<TL>::List()
	{
		pFirst = nullptr;
		PLast = nullptr;
		size = 0;
	}
	
	template<class TL>
	inline List<TL>::~List()
	{
		Element<TL>* pAux;
		while (pFirst != nullptr)
		{
			pAux = pFirst->getNext();
			delete pFirst;
			pFirst = pAux;
		}
	}

	template<class TL>
	inline void List<TL>::push(TL pData)
	{
		Element<TL>* pAux = pFirst;
		Element<TL>* insert = new Element<TL>;
		
		insert->setData(pData);
		PLast = insert;
		
		if (pFirst == nullptr)
		{
			pFirst = insert;
		}
		else
		{
			while (pAux->getNext() != nullptr)
			{
				pAux = pAux->getNext();
			}
			pAux->setNext(insert);
		}
		
		size++;
	}

	template<class TL>
	inline TL List<TL>::pop(TL pData)
	{
		Element<TL>* pAux = pFirst;
		Element<TL>* popElement = pFirst;
		
		if (pFirst->getData() == pData)
		{
			size--;
			pFirst = nullptr;
			return popElement->getData();
		}

		while (pAux != nullptr && pAux->getNext()->getData() != pData)
			pAux = pAux->getNext();

		popElement = pAux->getNext();
		pAux->setNext(popElement->getNext());
		size--;
		return TL(popElement->getData());
	}

	template<class TL>
	inline void List<TL>::remove(TL pData)
	{
		Element<TL>* pAux = pFirst;
		Element<TL>* pAux2 = nullptr;

		if (pFirst == nullptr)
			return;
		
		size--;
		if(pFirst->getData() == pData)
		{
			pFirst = pAux->getNext();
			delete pAux;
			return;
		}

		while (pAux->getData() != nullptr && pAux->getNext()->getData() != pData)
			pAux = pAux->getNext();
	
		pAux2 = pAux->getNext();
		pAux->setNext(pAux2->getNext());
	
		delete pAux2;
		pAux2 = nullptr;
	}

	template<class TL>
	inline TL List<TL>::getElement(int i)
	{
		Element<TL>* pAux = pFirst;

		for (int j = 0; j < i; j++)
		{
			pAux = pAux->getNext();
		}
		return pAux->getData();
	}
}
using namespace Matheus;
