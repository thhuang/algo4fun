class Solution:

    def minStickers(self, stickers: List[str], target: str) -> int:
        sticker_freqs = [Counter(sticker) for sticker in stickers]

        @cache
        def dfs(t: str) -> int:
            if not t:
                return 0

            result = inf
            freq = Counter(t)
            for sticker_freq in sticker_freqs:
                if t[0] not in sticker_freq:
                    continue
                new_t = "".join(
                    sorted([c * v for c, v in (freq - sticker_freq).items()]))
                result = min(result, 1 + dfs(new_t))
            return result

        result = dfs("".join(sorted([c for c in target])))
        return result if result < inf else -1
