type PriceSpan struct {
	Price int
	Span  int
}

type StockSpanner struct {
	PriceSpan []PriceSpan
}

func Constructor() StockSpanner {
	return StockSpanner{
		PriceSpan: []PriceSpan{},
	}
}

func (this *StockSpanner) Next(price int) int {
	span := 1
	for len(this.PriceSpan) > 0 && this.PriceSpan[len(this.PriceSpan)-1].Price <= price {
		span += this.PriceSpan[len(this.PriceSpan)-1].Span
		this.PriceSpan = this.PriceSpan[:len(this.PriceSpan)-1]
	}
	this.PriceSpan = append(this.PriceSpan, PriceSpan{price, span})
	return span
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Next(price);
 */
