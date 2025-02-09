use std::collections::HashMap;
use std::collections::HashSet;

impl Solution {
    pub fn query_results(limit: i32, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let mut index_to_color: HashMap<i32, i32> = HashMap::new();
        let mut color_to_indices: HashMap<i32, HashSet<i32>> = HashMap::new();

        queries
            .iter()
            .map(|query| {
                let (index, color) = (query[0], query[1]);
                if let Some(&color) = index_to_color.get(&index) {
                    index_to_color.remove(&index);
                    if let Some(&mut ref mut indices) = color_to_indices.get_mut(&color) {
                        indices.remove(&index);
                        if indices.is_empty() {
                            color_to_indices.remove(&color);
                        }
                    }
                }
                index_to_color.insert(index, color);
                color_to_indices
                    .entry(color)
                    .or_insert_with(HashSet::new)
                    .insert(index);
                color_to_indices.len() as i32
            })
            .collect()
    }
}
