require 'sequel'
require 'win32/sound'
require 'serialport'
include Win32

db = Sequel.sqlite('database.db')
begin
  port_file = 'COM3'
rescue Exception => e

end

baud_rate = 9600
data_bits = 8
stop_bits = 1
parity = SerialPort::NONE

port = SerialPort.new(port_file, baud_rate, data_bits, stop_bits, parity)

puts "######################################"
puts "          NSAgents-backend"
puts "   Made by Anton, CW, Eva and Isak"
puts "######################################"
puts " "

counter = 0

loop do
  print "Runda:"
  value = gets.chomp

  db['select * from movement where id = ?', value].each do |row|
    agent = case row[:agent]
      when "R" then "KGB"
      when "G" then "MI6"
      when "B" then "CIA"
      when "Y" then "Stasi"
              else "No agent."
            end
    turn = case row[:agent]
              when "R" then "r"
              when "G" then "g"
              when "B" then "b"
              when "Y" then "y"
            end
    sound = case row[:point]
              when -1 then "sound/Alarm01.wav"
              when 0 then "sound/Alarm02.wav"
              when 1 then "sound/Alarm03.wav"
              when 2 then "sound/Alarm04.wav"
            end

    movement = "#{row[:from]} till #{row[:to]}"
    points = "#{row[:point]} poäng. Har totalt #{row[:total]}"
    puts "#{agent} flyttar från #{movement} och får #{points}."
    port.write turn
    Sound.play(sound)
  end
end