#pragma once

namespace icf {

	template <class nodeType>
	class LinkList
	{
	public:
		struct Node
		{
			nodeType data;
			Node* next;
			Node* last;
		};
	private:
		Node* header;
		Node* footer;
	public:
		size_t length = 0;
		Node* add(nodeType data) {
			if (length <= 0) {
				header = new Node();
				header->data = data;
				footer = header;
			}
			else
			{
				Node* tmp = new Node();
				footer->next = tmp;
				tmp->last = footer;
				footer = footer->next;
				footer->data = data;
			}
			length++;
			return footer;
		}
		void del(size_t pos) {
			Node* node = operator[](pos);
			if (node == NULL) {
				return ;
			}
			//更换位置
			if (node == header) {
				if (length != 1) {
					header = header->next;
					header->last = NULL;
				}
				else {
					header = NULL;
					footer = 0;
				}
			}
			else if (node == footer) {
				footer = footer->last;
				footer->next = NULL;
			}
			else {
				node->last->next = node->next;
				node->next->last = node->last;
			}
			delete node;
			length--;
		}

		Node* insert(size_t pos, nodeType data) {
			Node* node = operator[](pos);
			if (node == NULL) {
				return NULL;
			}
			//插入位置
			Node* tmp = new Node();
			tmp->data = data;

			tmp->last = node->last;
			tmp->next = node;
			if (pos==0) {
				header->last = tmp;
				tmp->next = header;
				header = tmp;
			}
			else {
				node->last->next = tmp;
				node->last = tmp;
			}
			length++;
			return tmp;
		}
		Node* operator[](size_t  pos) const {
			if (pos > length) {
				return NULL;
			}
			Node* node = header;
			for (size_t i = 0; i < pos; i++)
			{
				node = node->next;
			}
			return node;
		}
	};
};