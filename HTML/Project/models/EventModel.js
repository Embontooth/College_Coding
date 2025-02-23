//For the Events
const mongoose = require('mongoose');
const EventSchema = new mongoose.Schema({
    name: { type: String, required: true },
    building: { type: mongoose.Schema.Types.ObjectId, ref: 'Building', required: true },
    // location: {
    //   type: { type: String, default: 'Point' },
    //   coordinates: [Number]
    // },
    startTime: { type: Date, required: true },
    endTime: { type: Date, required: true },
    information: { type: String },
    categories: [{ type: String }],
    // createdBy: { type: mongoose.Schema.Types.ObjectId, ref: 'ClubLeader', required: true }
  });
  // eventSchema.index({ location: '2dsphere' });
  EventSchema.index({ categories: 1 }); //Categories in ascending order
  EventSchema.index({ startTime: 1, endTime: 1 }); //Dates in ascending order
  module.exports = mongoose.model('Event', EventSchema);