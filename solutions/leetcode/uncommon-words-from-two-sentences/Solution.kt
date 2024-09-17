class Solution {
    fun uncommonFromSentences(s1: String, s2: String): Array<String> {
        val freq = mutableMapOf<String, Int>()

        s1.split(" ").forEach { w ->
            freq[w] = freq.getOrDefault(w, 0) + 1
        }
        s2.split(" ").forEach { w ->
            freq[w] = freq.getOrDefault(w, 0) + 1
        }

        val result = mutableListOf<String>()
        for ((word, count) in freq) {
            if (count == 1) {
                result.add(word)
            }
        }

        return result.toTypedArray()
    }
}