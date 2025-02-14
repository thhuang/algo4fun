struct ProductOfNumbers {
    product: Vec<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl ProductOfNumbers {
    fn new() -> Self {
        Self { product: vec![1] }
    }

    fn add(&mut self, num: i32) {
        if num == 0 {
            self.product = vec![1];
        } else {
            self.product.push(self.product.last().unwrap() * num)
        }
    }

    fn get_product(&self, k: i32) -> i32 {
        let k = k as usize;
        if k >= self.product.len() {
            return 0;
        }
        let n = self.product.len();
        self.product[n - 1] / self.product[n - k - 1]
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * let obj = ProductOfNumbers::new();
 * obj.add(num);
 * let ret_2: i32 = obj.get_product(k);
 */
