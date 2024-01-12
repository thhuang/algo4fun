type Trie struct {
	root *Node
}

func Constructor() Trie {
	return Trie{
		root: NewNode(),
	}
}

func (t *Trie) Insert(word string) {
	p := t.root
	for _, c := range word {
		if _, ok := p.children[c]; !ok {
			p.children[c] = NewNode()
		}
		p = p.children[c]
	}
	p.isEnd = true
}

func (t *Trie) Search(word string) bool {
	node := t.find(word)
	if node == nil {
		return false
	}
	return node.isEnd
}

func (t *Trie) StartsWith(prefix string) bool {
	return t.find(prefix) != nil
}

func (t *Trie) find(s string) *Node {
	p := t.root
	for _, c := range s {
		if _, ok := p.children[c]; !ok {
			return nil
		}
		p = p.children[c]
	}
	return p
}

type Node struct {
	children map[rune]*Node
	isEnd    bool
}

func NewNode() *Node {
	return &Node{
		children: map[rune]*Node{},
		isEnd:    false,
	}
}

/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */
