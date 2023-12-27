# Write your MySQL query statement below
SELECT a.player_id,a.event_date,sum(b.games_played) as games_played_so_far
FROM Activity a 
INNER JOIN Activity b#Self join
where a.player_id=b.player_id and a.event_date>=b.event_date
group by a.player_id,a.event_date
