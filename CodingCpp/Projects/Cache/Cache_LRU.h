#pragma once

#include <list>
#include <unordered_map>


namespace caches
{
    template <typename T, typename KeyT = int>
    struct cache_t
    {
        size_t sz_;
        std::list< std::pair<KeyT, T> > cache_;
        
        using ListIt = typename std::list< std::pair<KeyT, T> >::iterator;
        std::unordered_map< KeyT, ListIt > hash_;

        cache_t(size_t sz) : sz_(sz) {}

        bool full() const { return (cache_.size() == sz_); }

        template <typename F> bool lookup_update( KeyT key, F slow_get_page)
        {
            auto hit = hash_.find(key);
            
            if (hit == hash_.end())
            {
                if (full())
                {
                    hash_.erase(cache_.back().first);
                    cache_.pop_back();
                }
                cache_.emplace_front(key, slow_get_page(key));
                hash_.emplace(key, cache_.begin());
                return false;
            }

            auto eltit = hit->second;
            if (eltit != cache_.begin())
            {
                cache_.splice(cache_.begin(), cache_, eltit, std::next(eltit));
            }
            return true;
        }
    };
}
