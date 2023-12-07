SELECT player_id,device_id
from Activity
WHERE (player_id,event_date) in
(SELECT player_id,min(event_date)
FROM Activity
group by player_id)
