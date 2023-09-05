# Write your MySQL query statement below
SELECT a.machine_id, round(avg(b.timestamp-a.timestamp),3) as processing_time
FROM Activity a
JOIN Activity b 
    on a.machine_id=b.machine_id and a.process_id=b.process_id
    and a.activity_type='start' and b.activity_type='end'
group by a.machine_id

##
#We join the "Activity" table with itself using the "machine_id" column. This allows us to pair the start and end activities for each machine.
#We filter the rows to include only the start activities for the first occurrence and the end activities for the second occurrence. This ensures we have matched start and end activities for each machine.
#We calculate the time difference between the start and end activities for each machine by subtracting the start timestamp from the end timestamp.
#We use the AVG function to calculate the average processing time for each machine.
#We round the average processing time to three decimal places using the ROUND function.
#Finally, we group the results by "machine_id" to get the average processing time for each machine.
##
